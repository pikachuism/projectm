#ifndef Renderer_HPP
#define Renderer_HPP

#include "pbuffer.h"
#include "PresetFrameIO.hpp"
#include "BeatDetect.h"

#ifdef USE_FTGL
#include <FTGL/FTGL.h>
#include <FTGL/FTGLPixmapFont.h>
#include <FTGL/FTGLPolygonFont.h>
#endif /** USE_FTGL */

class BeatDetect;

class Renderer
{
  RenderTarget *renderTarget;
  BeatDetect *beatDetect;
  //per pixel equation variables
  float **gridx;  //grid containing interpolated mesh 
  float **gridy;
  float **origx2;  //original mesh 
  float **origy2;
  int gx;
  int gy;

  int vw; 
  int vh;
   
    float aspect;
 

  
 public:
 /// @bug hack to get glConsol

#ifdef USE_FTGL
FTGLPixmapFont *title_font;
FTGLPixmapFont *other_font;
FTGLPolygonFont *poly_font;
#endif /** USE_FTGL */
 
 int showfps;
    int showtitle;
    int showpreset;
    int showhelp;
    int showstats;

    int studio;
    int correction;

    char *presetName;
    char *fontURL;

    int noSwitch;

    int totalframes;
float realfps;
char *title;
    int drawtitle;

  Renderer( int width, int height, int gx, int gy, RenderTarget *renderTarget, BeatDetect *beatDetect, char *fontURL);
  ~Renderer();
  void RenderFrame(PresetOutputs *presetOutputs, PresetInputs *presetInputs);
  void reset(int w, int h);

private:

  void PerFrame(PresetOutputs *presetOutputs);
  void Interpolation(PresetOutputs *presetOutputs, PresetInputs *presetInputs);
  void PerPixelMath(PresetOutputs *presetOutputs,  PresetInputs *presetInputs);
  void reset_per_pixel_matrices();
  void rescale_per_pixel_matrices();
  void maximize_colors(PresetOutputs *presetOutputs);
  void render_texture_to_screen(PresetOutputs *presetOutputs);
  void draw_fps( float realfps );
  void draw_stats(PresetInputs *presetInputs);
  void draw_help( );
  void draw_preset();
  void draw_title();
  void draw_title_to_screen();
  void maximize_colors();
  void draw_title_to_texture();
  void draw_motion_vectors(PresetOutputs *presetOutputs);
  void draw_borders(PresetOutputs *presetOutputs);
  void draw_shapes(PresetOutputs *presetOutputs);
  void draw_custom_waves(PresetOutputs *presetOutputs);
  void draw_waveform(PresetOutputs *presetOutputs, PresetInputs *presetInputs);
  void modulate_opacity_by_volume(PresetOutputs *presetOutputs) ;
  void darken_center();
};

#endif
