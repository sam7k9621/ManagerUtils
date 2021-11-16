from ManagerUtils.PlotUtils.Constants import *
import ROOT
# /*******************************************************************************
# *   Pad settings functions
# *******************************************************************************/
def NewCanvas( obj="c" ):
    ROOT.gROOT.SetBatch(ROOT.kTRUE)
    c = ROOT.TCanvas( obj, obj, DEFAULT_CANVAS_WIDTH, DEFAULT_CANVAS_HEIGHT )
    return c

def NewTopPad():
    pad = ROOT.TPad( "toppad", "", 0., TOP_BOTTOM_SEP, 1., 1. )
    pad.SetTicks( 1, 1 )
    pad.SetBottomMargin( 0.05 )
    pad.SetLeftMargin( PLOT_X_MIN )
    pad.SetRightMargin( 1 - PLOT_X_MAX )
    pad.SetTopMargin( ( 1 - PLOT_Y_MAX ) / ( 1 - TOP_BOTTOM_SEP ) )
    return pad

def NewBottomPad():
    pad = ROOT.TPad( "botpad", "", 0., 0.0, 1., TOP_BOTTOM_SEP )
    pad.SetTicks( 1, 1 )
    pad.SetTopMargin( 0.025 )
    pad.SetLeftMargin( PLOT_X_MIN )
    pad.SetRightMargin( 1 - PLOT_X_MAX )
    pad.SetBottomMargin( ( PLOT_Y_MIN ) / ( TOP_BOTTOM_SEP ) )
    return pad

def NewNCanvas( obj="c" ):
    ROOT.gROOT.SetBatch( ROOT.kTRUE )
    c = ROOT.TCanvas( obj, obj, DEFAULT_NCANVAS_WIDTH, DEFAULT_NCANVAS_HEIGHT )
    return c

def NewNTopPad():
    pad = ROOT.TPad( "toppad", "", 0., NTOP_MIDDLE_SEP, 1., 1. )
    pad.SetTicks( 1, 1 )
    pad.SetBottomMargin( 0.05 )
    pad.SetLeftMargin( PLOT_X_MIN )
    pad.SetRightMargin( 1 - PLOT_X_MAX )
    pad.SetTopMargin( 0.17 )
    return pad

def NewNMiddlePad():
    pad = ROOT.TPad( "midpad", "", 0., NTOP_BOTTOM_SEP, 1., NTOP_MIDDLE_SEP )
    pad.SetTicks( 1, 1 )
    pad.SetTopMargin( 0.005 )
    pad.SetBottomMargin( 0.1 )
    pad.SetLeftMargin( PLOT_X_MIN )
    pad.SetRightMargin( 1 - PLOT_X_MAX )
    return pad

def NewNBottomPad():
    pad = ROOT.TPad( "botpad", "", 0., 0.0, 1., NTOP_BOTTOM_SEP )
    pad.SetTicks( 1, 1 )
    pad.SetTopMargin( 0.025 )
    pad.SetLeftMargin( PLOT_X_MIN )
    pad.SetRightMargin( 1 - PLOT_X_MAX )
    pad.SetBottomMargin( ( PLOT_Y_MIN ) / ( NTOP_BOTTOM_SEP ) )
    return pad

def SetSinglePad( c ):
    c.SetTicks( 1, 1)
    c.SetLeftMargin( PLOT_X_MIN )
    c.SetRightMargin( 1 - PLOT_X_MAX )
    c.SetBottomMargin( PLOT_Y_MIN )
    c.SetTopMargin( 1 - PLOT_Y_MAX )
    c.Update()
    # update after settings 

def SetSinglePadWithPalette( c ): 
    c.SetTicks( 1, 1)
    c.SetLeftMargin( PLOT_X_MIN )
    c.SetBottomMargin( PLOT_Y_MIN )
    c.SetTopMargin( 1 - PLOT_Y_MAX )
    c.Update()

# /*******************************************************************************
# *   New Legend settings
# *******************************************************************************/
def NewLegend( xmin, ymin, xmax, ymax ):
    leg = ROOT.TLegend( xmin, ymin, xmax, ymax )
    leg.SetBorderSize( 0 )
    leg.SetTextFont( FONT_TYPE )
    leg.SetTextSize( TEXT_FONT_SIZE )
    leg.SetFillColorAlpha( 0, 0 )
    leg.SetLineColor( ROOT.kWhite )
    return leg

def NewTextBox( xmin, ymin, xmax, ymax ):
    text = ROOT.TPaveText( xmin, ymin, xmax, ymax, "NDC" )
    text.SetTextFont( FONT_TYPE )
    text.SetTextSize( TEXT_FONT_SIZE )
    text.SetFillColor( ROOT.kWhite )
    return text

def DrawEntryLeft( entry ):
    tl = ROOT.TLatex()
    tl.SetNDC( True )
    tl.SetTextFont( FONT_TYPE )
    tl.SetTextSize( TEXT_FONT_SIZE )
    tl.SetTextAlign( BOTTOM_LEFT )
    tl.DrawLatex( PLOT_X_MIN, PLOT_Y_MAX + TEXT_MARGIN / 2, entry )

def DrawEntryRight( entry ):
    tl = ROOT.TLatex()
    tl.SetNDC( True )
    tl.SetTextFont( FONT_TYPE )
    tl.SetTextSize( TEXT_FONT_SIZE )
    tl.SetTextAlign( BOTTOM_RIGHT )
    tl.DrawLatex( PLOT_X_MAX, PLOT_Y_MAX + ( TEXT_MARGIN / 2 ), entry )

def DrawEntry( x, y, entry, size=TEXT_FONT_SIZE ):
    tl = ROOT.TLatex()
    tl.SetTextFont( FONT_TYPE )
    tl.SetTextSize( size )
    tl.SetTextAlign( 12 )
    tl.DrawLatex( x, y, entry )

# /*******************************************************************************
# *    Plot CMS label
# *******************************************************************************/
def DrawCMSLabel( tag="" ):
    tl = ROOT.TLatex()
    tl.SetNDC( True )
    tl.SetTextFont( FONT_TYPE )
    tl.SetTextSize( AXIS_TITLE_FONT_SIZE )
    tl.SetTextAlign( TOP_LEFT )
    tl.DrawLatex( PLOT_X_MIN + TEXT_MARGIN, PLOT_Y_MAX - TEXT_MARGIN, "#bf{CMS}" )

    if tag == PRELIMINARY:
        tl.DrawLatex( PLOT_X_MIN + TEXT_MARGIN, PLOT_Y_MAX - TEXT_MARGIN - LINE_HEIGHT, "#it{Preliminary}" )
    
    elif tag == SIMULATION:
        tl.DrawLatex( PLOT_X_MIN + TEXT_MARGIN, PLOT_Y_MAX - TEXT_MARGIN - LINE_HEIGHT, "#it{Simulation}" )
    
    elif tag == PRESIMULATION:
        tl.DrawLatex( PLOT_X_MIN + TEXT_MARGIN, PLOT_Y_MAX - TEXT_MARGIN - LINE_HEIGHT, "#it{Simulation Preliminary}" )

def DrawCMSLabelOuter( tag="" ):
    tl = ROOT.TLatex()
    tl.SetNDC( True )
    tl.SetTextFont( FONT_TYPE )
    tl.SetTextSize( AXIS_TITLE_FONT_SIZE )
    tl.SetTextAlign( BOTTOM_LEFT )
    text = "#bf{CMS} "

    if tag == PRELIMINARY:
        text += "#it{Preliminary}"
    elif tag == SIMULATION:
        text += "#it{Simulation}"
    elif tag == PRESIMULATION:
        text += "#it{Simulation Preliminary}"

    tl.DrawLatex( PLOT_X_MIN, PLOT_Y_MAX + TEXT_MARGIN / 2, text )

def DrawLuminosity( lumi ):
    tl = ROOT.TLatex()
    tl.SetNDC( True )
    tl.SetTextFont( FONT_TYPE )
    tl.SetTextSize( AXIS_TITLE_FONT_SIZE )
    buffer = "{0}fb^{{-1}} ({1} TeV)".format( lumi / 1000, 13 )
    # buffer = "{0:.1f}fb^{{-1}} ({1} TeV)".format( lumi / 1000., 13 )
    tl.SetTextAlign( BOTTOM_RIGHT )
    tl.DrawLatex( PLOT_X_MAX, PLOT_Y_MAX + ( TEXT_MARGIN / 2 ), buffer )
