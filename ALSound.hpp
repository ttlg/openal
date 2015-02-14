
#pragma once

#include <AL/alut.h>
#include <AL/al.h>

class ALSound
{
public:
	ALSound( const char *fname );
	ALSound();
	~ALSound();
	static void setListenerPos( float x, float y, float z );
	ALSound* load( const char *fname );
	void play();
	void stop();
	ALSound* pause();
	ALSound* setVolume( float g );
	ALSound* enableLooping( );
	ALSound* disableLooping( );
	bool isPlaying();
	void setPosition( float x, float y, float z );
	void enableSourceRelative();
	void disableSourceRelative();
	void setVelocity( float x, float y, float z );

private:
	ALuint		buf, src;
	ALfloat		volume; /* 0 ~ 1 */ 
	ALfloat		pos[3];
	ALfloat		vel[3];
	static	ALfloat listenerPos[3];
};

