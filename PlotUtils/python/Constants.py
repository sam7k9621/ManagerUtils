import ROOT
from itertools import cycle

# /*******************************************************************************
# *   Default canvas settings
# *******************************************************************************/
DEFAULT_CANVAS_WIDTH  = 650
DEFAULT_CANVAS_HEIGHT = 500

DEFAULT_NCANVAS_WIDTH  = 650
DEFAULT_NCANVAS_HEIGHT = 650

# /*******************************************************************************
# *   Default padding settings
# *******************************************************************************/
PLOT_X_MIN = 0.13
PLOT_Y_MIN = 0.105
PLOT_X_MAX = 0.95
PLOT_Y_MAX = 0.9
TOP_BOTTOM_SEP = 0.3

NTOP_MIDDLE_SEP = 0.46
NTOP_BOTTOM_SEP = 0.27

# /*******************************************************************************
# *   Font setting
# *******************************************************************************/
FONT_TYPE = 43 #Sans + absolute font size
AXIS_TITLE_FONT_SIZE = 22
AXIS_LABEL_FONT_SIZE = 18
TEXT_FONT_SIZE = 18

# /*******************************************************************************
# *   Text alignment settings
# *******************************************************************************/
BOTTOM_LEFT  = 11
BOTTOM_RIGHT = 31
TOP_LEFT     = 13
TOP_RIGHT    = 33

TEXT_MARGIN      = 0.04
TEXT_HEIGHT      = ( float(TEXT_FONT_SIZE) / float(DEFAULT_CANVAS_HEIGHT) )
REL_LINE_HEIGHT  = 1.5
LINE_HEIGHT      = ( TEXT_HEIGHT * REL_LINE_HEIGHT )
PLOT_X_TEXT_MIN  = ( ( PLOT_X_MIN ) + ( TEXT_MARGIN ) )
PLOT_X_TEXT_MAX  = ( (PLOT_X_MAX)-( TEXT_MARGIN ) )
PLOT_Y_TEXT_MIN  = ( ( PLOT_Y_MIN ) + ( TEXT_MARGIN ) )
PLOT_Y_TEXT_MAX  = ( (PLOT_Y_MAX) - ( TEXT_MARGIN ) )

# /*******************************************************************************
# *   Label plotting
# *******************************************************************************/
PRELIMINARY = 0
SIMULATION  = 1
PRESIMULATION  = 2
PUBLISH     = -1

# /*******************************************************************************
# *   Plot common settings
# *******************************************************************************/
Gray    = ROOT.kGray + 1
Magenta = ROOT.kMagenta + 2
Red     = ROOT.kRed - 7
Orange  = ROOT.kOrange + 1
Azure   = ROOT.kAzure - 3
Green   = ROOT.kGreen - 6
Yellow  = ROOT.kYellow + 2
Cyan    = ROOT.kCyan + 1
Blue    = ROOT.kBlue + 2
sigcolorlst = [ Red+4, Red, Red+2 ]
colorlst    = [ Gray, Magenta, Azure, Orange, Green, Cyan, Yellow ] 
colorcycle     = cycle( colorlst ) 
sigcolorcycle  = cycle( sigcolorlst ) 
markerlst   = [ 22, 29, 39, 41, 47, 23, 5, 48] 
markercycle = cycle( markerlst )

