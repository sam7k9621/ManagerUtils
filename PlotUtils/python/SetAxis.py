from decimal import Decimal
from ManagerUtils.PlotUtils.Constants import *
from ROOT import TGaxis, gPad
import re

def SetTitleDigit( y, diglst ):
    diglst = [ int( ( '%E' % x ).split("E")[1] ) for x in diglst ]
    max_digits = max( [ x for x in diglst ], key=abs ) 
    digits = int( float( max_digits ) / ( TGaxis.GetMaxDigits() ) ) * ( TGaxis.GetMaxDigits() - 1 ) 
    
    if digits:
        y.SetTitle( y.GetTitle() + " (x 10^{{{}}})".format( digits ) )

def SetTitleBinWidth( plot ):
    try: 
        width = plot.GetBinWidth( 0 )
    except:
        width = 0 
   
    x = plot.GetXaxis()
    y = plot.GetYaxis()
    if width:
        y.SetTitle( y.GetTitle() + " / {}".format( width ) )

def Set3DAxis( plot ):
    # Global settings from TGaxis
    TGaxis.SetMaxDigits( 4 )
    TGaxis.SetExponentOffset( -1000, -1000 )

    # X-axis settings
    x = plot.GetXaxis()
    x.SetLabelFont( FONT_TYPE )
    x.SetTitleFont( FONT_TYPE )
    x.SetLabelSize( AXIS_LABEL_FONT_SIZE )
    x.SetTitleSize( AXIS_TITLE_FONT_SIZE )
    x.SetTitleOffset( 1.5 )
 
    # Y-axis settings
    y = plot.GetYaxis()
    y.SetLabelFont( FONT_TYPE )
    y.SetTitleFont( FONT_TYPE )
    y.SetLabelSize( AXIS_LABEL_FONT_SIZE )
    y.SetTitleSize( AXIS_TITLE_FONT_SIZE )
    y.SetTitleOffset( 1.5 )
    
    # Z-axis settings
    z = plot.GetZaxis()
    z.SetLabelFont( FONT_TYPE )
    z.SetTitleFont( FONT_TYPE )
    z.SetLabelSize( AXIS_LABEL_FONT_SIZE )
    z.SetTitleSize( AXIS_TITLE_FONT_SIZE )
    z.SetTitleOffset( 1.3 )
    
    SetTitleDigit( y, [ gPad.GetUymax(), gPad.GetUymin() ] )
    SetTitleDigit( x, [ gPad.GetUxmax(), gPad.GetUxmin() ] )

def Set2DAxis( plot ):
    # Global settings from TGaxis
    TGaxis.SetMaxDigits( 4 )
    TGaxis.SetExponentOffset( -1000, -1000 )

    # X-axis settings
    x = plot.GetXaxis()
    x.SetLabelFont( FONT_TYPE )
    x.SetTitleFont( FONT_TYPE )
    x.SetLabelSize( AXIS_LABEL_FONT_SIZE )
    x.SetTitleSize( AXIS_TITLE_FONT_SIZE )
 
    # Y-axis settings
    y = plot.GetYaxis()
    y.SetLabelFont( FONT_TYPE )
    y.SetTitleFont( FONT_TYPE )
    y.SetLabelSize( AXIS_LABEL_FONT_SIZE )
    y.SetTitleSize( AXIS_TITLE_FONT_SIZE )
    y.SetTitleOffset( 1.2 )
    
    SetTitleDigit( y, [ gPad.GetUymax(), gPad.GetUymin() ] )
    SetTitleDigit( x, [ gPad.GetUxmax(), gPad.GetUxmin() ] )

def SetAxis( plot, binwidth=True, digit=True ):
    # Global settings from TGaxis
    TGaxis.SetMaxDigits( 4 )
    TGaxis.SetExponentOffset( -1000, -1000 )

    # X-axis settings
    x = plot.GetXaxis()
    x.SetLabelFont( FONT_TYPE )
    x.SetTitleFont( FONT_TYPE )
    x.SetLabelSize( AXIS_LABEL_FONT_SIZE )
    x.SetTitleSize( AXIS_TITLE_FONT_SIZE )
 
    # Y-axis settings
    y = plot.GetYaxis()
    y.SetLabelFont( FONT_TYPE )
    y.SetTitleFont( FONT_TYPE )
    y.SetLabelSize( AXIS_LABEL_FONT_SIZE )
    y.SetTitleSize( AXIS_TITLE_FONT_SIZE )
    y.SetTitleOffset( 1.2 )
    
    if binwidth:
        SetTitleBinWidth( plot )
    if digit:
        SetTitleDigit( y, [ gPad.GetUymax(), gPad.GetUymin() ] )

def SetTopPlotAxis( plot, binwidth=True, digit=True ):
    SetAxis( plot, binwidth, digit )
    plot.GetXaxis().SetLabelSize( 0 )
    plot.GetXaxis().SetTitleSize( 0 )
    plot.GetYaxis().SetTitleOffset( 1.5 )

def SetMiddlePlotAxis( plot, binwidth=False, digit=True ):
    SetAxis( plot, binwidth, digit )
    plot.GetXaxis().SetLabelSize( 0 )
    plot.GetXaxis().SetTitleSize( 0 )
    plot.GetYaxis().SetNdivisions( 503 )
    plot.GetYaxis().SetTitleOffset( 1.5 )
    
def SetBottomPlotAxis( plot, binwidth=False, digit=True ):
    SetAxis( plot, binwidth, digit )
    plot.GetYaxis().SetNdivisions( 503 )
    plot.GetXaxis().SetTitleOffset( 3.0 )
    plot.GetYaxis().SetTitleOffset( 1.5 )

def SetNormToUnity( plot ):
    norm = plot.Integral()
    plot.Scale( 1 / norm )
    return plot
