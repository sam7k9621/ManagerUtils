import sys
import math
# /*******************************************************************************
# *   Getting histogram graphically maximum point
# *******************************************************************************/
def GetHistYmax( hist ):
    ans = 0
    for i in range( hist.GetNcells() ):
        bincont = abs( hist.GetBinContent( i ) )
        binerr  = abs( hist.GetBinError( i ) )
        ans = max( ans, bincont + binerr )
    return ans

def GetHistlstYmax( histlst ):
    ans = 0
    for hist in histlst:
        ans = max( ans, GetHistYmax( hist ) )
    return ans

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
        ans = min( ans, GetGraphYmin( graph ) )
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
        if num.GetBinContent( i ) == 0 and den.GetBinContent( i ) == 0:
            ans.SetBinContent( i, cen )
    return ans;

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
