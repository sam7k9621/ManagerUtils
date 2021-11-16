import ROOT 

def SaveToROOT( h, filename, objname ):
    myfile = ROOT.TFile.Open( filename, "UPDATE" )
    h.Write( objname, ROOT.TObject.kOverwrite )
    myfile.Close()
