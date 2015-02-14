
#include "ALSound.hpp"

int main(int argc, char* argv[]){
  alutInit( &argc, argv );

  ALSound *sound = new ALSound();
  sound->load( "sound.wav" )->enableLooping();
  sound->setVolume( 0.3 );
  sound->play();
  alutSleep( 3 ); /* sleep 3 second*/
  sound->stop();
  delete sound;

  return 0;
}
