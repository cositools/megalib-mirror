/*
 * MImageGalactic.h
 *
 * Copyright (C) by Andreas Zoglauer.
 * All rights reserved.
 *
 * Please see the source-file for the copyright-notice.
 *
 */


#ifndef __MImageGalactic__
#define __MImageGalactic__


////////////////////////////////////////////////////////////////////////////////


// ROOT libs:
#include <TGaxis.h>

// MEGAlib libs:
#include "MGlobal.h"
#include "MImage2D.h"

// Forward declarations:


////////////////////////////////////////////////////////////////////////////////


class MImageGalactic : public MImage2D
{
  // public interface:
 public:
  //! Default constructor
  MImageGalactic();
  //! Standard constructor
  MImageGalactic(MString Title, double* Array,
                 MString xTitle, double xMin, double xMax, int xNBins, 
                 MString yTitle, double yMin, double yMax, int yNBins, 
                 MString vTitle, int Spectrum = c_Rainbow, int DrawOption = c_COLCONT4Z,
                 MString SourceCatalog = "");
  //! Standard destructor
  virtual ~MImageGalactic();

  //! Set the image projection
  void SetProjection(MImageProjection Projection) { m_Projection = Projection; }
  
  //! Clone this image
  virtual MImage* Clone();

  //! Set the image array and redisplay it
  virtual void SetImageArray(double* Array);

  //! Display the histogram in the given canvas
  virtual void Display(TCanvas* Canvas = nullptr);
 
  // protected methods:
 protected:
  // Add the named sources to the display
  void AddNamedSources();

  // Display unprojected
  void DisplayProjectionNone();
  // Display with Hammer projection
  void DisplayProjectionHammer();
  
  
  // private methods:
 private:
  //! Convert lat and long (in rad) to x & y in the Hammer histogram
  void HammerConv(double Long, double Lat, double CentralMeridian, double& xHammer, double& yHammer);
  //! Convert x & y in the Hammer histogram to lat and long (in rad)
  bool HammerInvConv(double xHammer, double yHammer, double CentralMeridian, double& Long, double& Lat);

  // protected members:
 protected:

  // private members:
 private:
  //! The projection
  MImageProjection m_Projection;
   
  //! The new x axis's
  TGaxis* m_XAxis;

  //! The name of the source catalog
  MString m_SourceCatalog;

#ifdef ___CINT___
 public:
  ClassDef(MImageGalactic, 0) // class containing an astropysical image
#endif

};

#endif


////////////////////////////////////////////////////////////////////////////////
