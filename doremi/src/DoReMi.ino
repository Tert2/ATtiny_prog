#include "SimpleYMF825.h"
#include <Arduino.h>

SimpleYMF825 YMF825;

int channel = 1;
int ch = 2;
int c = 3;
int x = 220;
int y = 150;

void setup()
{
    YMF825.begin(IOVDD_5V);     // for 5V McU

    //YMF825.begin(IOVdd_3V3); // for 3.3V McU
    
    // YMF825.setTone( 0, gRaNd_PIaNO );
    YMF825.setTone( 1, E_PIANO );
    YMF825.setTone( 2, TENOR_SAX );
    YMF825.setTone( 3, PICK_BASS );
    // YMF825.setTone( 4, TNKL_BeLL );
    // YMF825.setTone( 5, NeW_age_Pd );  
        // YMF825.setTone( 6, BRIgHT_PIaNO );
    // YMF825.setTone( 7, VIBes );
    // YMF825.setTone( 8, cHURcH_ORgaN );
    // YMF825.setTone( 9, FLUTE );
    // YMF825.setTone(10, ROcK_ORgaN );
    // YMF825.setTone(11, NYLON_gUITeR );
    // YMF825.setTone(12, SQUARE_LEAD );
    // YMF825.setTone(13, saW_Lead );
    // YMF825.setTone(14, HaRPsIcHORd );
    // YMF825.setTone(15, HaRMONIca );
    
    YMF825.setMasterVolume(32);
    
    for(int ch=0;ch<16;ch++){
        YMF825.setVolume(ch, 25);
    }               
    pinMode(A6, INPUT_PULLUP);
}

void loop()
{
  YMF825.keyon(channel, 4, F);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, C);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, G);
    YMF825.keyon(ch, 3, E);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 3, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, E);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, E);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, F);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, G);
    YMF825.keyon(ch, 3, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    
    YMF825.keyon(channel, 4, GS);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 3, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, DS);
    delay(x/2+x/4);
    YMF825.keyoff(channel);
    delay(x/4);
    YMF825.keyoff(ch);

    YMF825.keyon(channel, 4, GS);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, DS);
    delay(x/2);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, AS);
    delay(x/2);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, G);
    YMF825.keyon(ch, 3, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    
    YMF825.keyon(channel, 4, GS);
    YMF825.keyon(ch, 3, D);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, D);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, D);
    delay(x/2);
    YMF825.keyoff(channel);
    delay(x/2);
    YMF825.keyoff(ch);

    YMF825.keyon(channel, 5, C);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 3, CS);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 4, CS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, CS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, CS);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 3, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, GS);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, G);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, C);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);


    
    
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(channel, 4, GS);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, AS);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, C);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, AS);
    YMF825.keyon(ch, 3, E);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 3, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, E);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(channel, 5, E);
    YMF825.keyon(ch, 4, E);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 3, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, C);
    YMF825.keyon(ch, 3, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4,AS);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, G);
    YMF825.keyon(ch, 4, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, AS);
    YMF825.keyon(ch, 4, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, GS);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, AS);
    YMF825.keyon(ch, 3, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, GS);
    YMF825.keyon(ch, 3, D);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, G);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, D);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, GS);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, D);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, G);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, GS);
    YMF825.keyon(ch, 3, CS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, G);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 4, CS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, CS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, GS);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, G);
    YMF825.keyon(ch, 3, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 4, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5 , F);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, G);
    YMF825.keyon(ch, 4, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, C);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 3, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);


  
    YMF825.keyon(channel, 4, F);
    YMF825.keyon(c, 4, C);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 5, C);
    YMF825.keyon(c, 4, GS);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 4, G);
    YMF825.keyon(c, 4, E);
    YMF825.keyon(ch, 3, E);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, E);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 4, F);
    YMF825.keyon(ch, 3, E);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, G);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    
    YMF825.keyon(channel, 4, GS);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, GS);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, G);
    delay(x/2);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, AS);
    delay(x/2);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, G);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, GS);
    YMF825.keyon(c, 5, F);
    YMF825.keyon(ch, 3, D);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, D);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 5, C);
    YMF825.keyon(ch, 3, D);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(c, 5, DS);
    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 3, CS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(c, 4, AS);
    YMF825.keyon(ch, 3, CS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 5, CS);
    YMF825.keyon(c, 4, AS);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, CS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(c, 4, G);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);


    YMF825.keyon(channel, 5, GS);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 5, G);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, C);
    YMF825.keyon(c, 4, GS);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);
    
    YMF825.keyon(channel, 4, GS);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, AS);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, C);
    YMF825.keyon(c, 4, GS);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(c, 5, C);
    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(c, 4, G);
    YMF825.keyon(channel, 4, AS);
    YMF825.keyon(ch, 3, E);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, E);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 5, E);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, E);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, C);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, AS);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);





    YMF825.keyon(channel, 5, G);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 4, AS);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, GS);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5,AS);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, GS);
    YMF825.keyon(c,5, D);
    YMF825.keyon(ch, 3, D);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 5, G);
    YMF825.keyon(c, 5, D);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, D);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 5, GS);
    YMF825.keyon(c, 5, F);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 3, D);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, G);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, GS);
    YMF825.keyon(c, 5, DS);
    YMF825.keyon(ch, 3, CS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, G);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 3, CS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, CS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, GS);
    YMF825.keyon(c, 5, DS);
    YMF825.keyon(ch, 3, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);
    YMF825.keyoff(c);

    YMF825.keyon(channel, 5, G);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, G);
    YMF825.keyon(ch, 4, G);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, C);
    YMF825.keyon(ch, 3, DS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, DS);
    YMF825.keyon(ch, 3, AS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyoff(channel);

    YMF825.keyon(channel, 5, F);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);

    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 3, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, C);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, F);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 4, GS);
    delay(x);
    YMF825.keyoff(ch);
    YMF825.keyon(ch, 5, C);
    delay(4*x);
    YMF825.keyoff(ch);
  }