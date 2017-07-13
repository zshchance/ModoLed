#define EXT extern
#include "pins.h"
#include "global_var.h"

void set_trip_brig(int bri_val){
    for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(bri_val,bri_val,bri_val)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}


