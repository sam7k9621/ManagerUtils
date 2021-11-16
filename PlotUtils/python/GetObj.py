import sys
import math
from ManagerUtils.PlotUtils.Constants import *
from array import array
from ROOT import TGraphAsymmErrors
# /*******************************************************************************
# *   Getting histogram graphically maximum point
# *******************************************************************************/
def GetHistYmax( hist ):
    ans = 0
    for i in range( 1, hist.GetNbinsX()+1 ):
        bincont = abs( hist.GetBinContent( i ) )
        binerr  = abs( hist.GetBinError( i ) )
        ans = max( ans, bincont + binerr )
    return ans

def GetHistlstYmax( histlst ):
    ans = 0
    for hist in histlst:
        ans = max( ans, GetHistYmax( hist ) )
    return ans

def CutOnHist( hist, idx ):
    for i in range( idx+1, hist.GetNcells() ):
        hist.SetBinContent( i, 0 )
        hist.SetBinError( i, 0 )
    return hist

# /*******************************************************************************
# *   TGraph Max and min calculations
# *******************************************************************************/
def GetGraphYmax( gr ):
    ans = -sys.maxint

    for i in range( gr.GetN() ):
        bin = gr.GetY()[ i ] + gr.GetErrorYhigh( i )
        ans = max( ans, bin )
    return ans

def GetGraphYmin( gr ):
    ans = sys.maxint

    for i in range( gr.GetN() ):
        bin = gr.GetY()[ i ] - gr.GetErrorYlow( i )
        ans = min( ans, bin )
    return ans

def GetGraphlstYmax( grlst ):
    ans = -sys.maxint
    
    for gr in grlst:
        ans = max( ans, GetGraphYmax( gr ) )
    return ans

def GetGraphlstYmin( grlst ):
    ans = sys.maxint

    for gr in grlst:
        ans = min( ans, GetGraphYmin( gr ) )
    return ans

# /*******************************************************************************
# *   TH1D division functions
# *******************************************************************************/
def Divide2DTeff( num, den, syst=0.01, cen=0 ):
    ans = num.GetCopyTotalHisto()
    ans_err = num.GetCopyTotalHisto()

    xbins = ans.GetXaxis().GetNbins()
    ybins = ans.GetYaxis().GetNbins()

    for i in range( xbins+2 ):
        for j in range( ybins+2 ):
            nbin = num.GetGlobalBin( i, j )
            neff = num.GetEfficiency( nbin )
            nerr = num.GetEfficiencyErrorLow( nbin )

            dbin = den.GetGlobalBin( i, j )
            deff = den.GetEfficiency( dbin )
            derr = den.GetEfficiencyErrorLow( dbin )

            if deff != 0:
                seff = neff / deff
                serr = math.sqrt( ErrorProp( neff, nerr, deff, derr )**2  + (seff * syst)**2 )
            else:
                seff = cen
                serr = cen

            ans.    SetBinContent( i, j, seff )
            ans.    SetBinError  ( i, j, serr )
            ans_err.SetBinContent( i, j, serr )

    return (ans, ans_err)

def DivideHist( num, den, cen=0 ):
    ans = num.Clone()
    ans.Divide( den )

    for i in range( num.GetNcells() ):
        if num.GetBinContent( i ) == 0 or den.GetBinContent( i ) == 0:
            ans.SetBinContent( i, cen )
    return ans

def GetErrRatioPlot( hist, up, dn, cen=False ):
    x, y     = array( 'd' ), array( 'd' )
    exl, exh = array( 'd' ), array( 'd' )
    eyl, eyh = array( 'd' ), array( 'd' )

    # No overflow bins in TGraph
    for i in range( hist.GetNbinsX() ):
        x.append( hist.GetBinCenter( i+1 ) )
        y.append( hist.GetBinContent( i+1 ) if cen else 1 )
        exl.append( hist.GetBinWidth( i+1 ) / 2. )
        exh.append( hist.GetBinWidth( i+1 ) / 2.)
        eyl.append( dn[ i ] )
        eyh.append( up[ i ] )

    ans = TGraphAsymmErrors( hist.GetNbinsX(), x, y, exl, exh, eyl, eyh )
    return ans

def ErrorProp( x1, m1, x2, m2  ):
    return math.sqrt( m1**2 / x2**2 + m2**2 * x1**2 /x2**4 )

def DivideGraph( num, den, cen=0 ):
    ans = num.Clone()
    for i in range( num.GetN() ):
        numy = num.GetY()[i]
        numyerrlo = num.GetErrorYlow( i )
        numyerrhi = num.GetErrorYhigh( i )

        deny = den.GetY()[i]
        denyerrlo = den.GetErrorYlow( i )
        denyerrhi = den.GetErrorYhigh( i )

        numx = num.GetX()[i]
        xerrlo = num.GetErrorXlow( i )
        xerrhi = num.GetErrorXhigh( i )


        if deny:
            ans.SetPoint( i, numx, (numy / deny) - cen )
            ans.SetPointError( 
                    i, xerrlo, xerrhi, 
                    ErrorProp( numy, numyerrlo, deny, denyerrlo ),
                    ErrorProp( numy, numyerrhi, deny, denyerrhi )
                    )
        else:
            ans.SetPoint( i, numx, 0 )
    
    ans.SetTitle( "" )
    return ans


# /*******************************************************************************
# *   TH1D summation functions
# *******************************************************************************/
def SumHist( histlst ):
    hist = histlst[0].Clone()
    for h in histlst[1:]:
        hist.Add(h)
    return hist

def GetColor():
    return next( colorcycle )

def GetMarker():
    return next( markercycle )
