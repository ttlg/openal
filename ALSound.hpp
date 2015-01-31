
#ifndef ALSOUND_H
#define ALSOUND_H

#include <stdio.h>
#include "../include/alut.h"

class ALSound
{
private:
	ALuint		buf, src;
	ALfloat		volume; /* 0 Å` 1 */ 
	ALfloat		pos[3];
	ALfloat		vel[3];

	static	ALfloat listenerPos[3];
	
public:

	ALSound( const char *fname ): buf(0), src(0)
	{
		alGenBuffers( 1, &buf );
		alGenSources( 1, &src );
		buf = alutCreateBufferFromFile( fname );
		if ( buf == AL_NONE )
		{
			printf("%sÇÕì«Ç›çûÇﬂÇ‹ÇπÇÒÇ≈ÇµÇΩ\n", fname );
		}
		alSourcei( src, AL_BUFFER, buf );
		alSourcei( src, AL_LOOPING, AL_FALSE );
	}
	ALSound(): buf(0), src(0)
	{
		alGenBuffers( 1, &buf );
		alGenSources( 1, &src );
	}

	~ALSound()
	{
		alDeleteBuffers( 1, &buf );
		alDeleteSources( 1, &src );
	}

	void load( char *fname )
	{
		buf = alutCreateBufferFromFile( fname );
		alSourcei( src, AL_BUFFER, buf );
		alSourcei( src, AL_LOOPING, AL_FALSE );
	}
	void play()
	{
		alSourcePlay( src );
	}

	void stop()
	{
		alSourceStop( src );
	}

	ALSound* pause()
	{
		alSourcePause( src );
		return this;
	}

	ALSound* setVolume( float g )
	{
		alSourcef( src, AL_GAIN, g );
		return this;
	}

	ALSound* enableLooping( )
	{
		alSourcei( src, AL_LOOPING, AL_TRUE );
		return this;
	}

	ALSound* disableLooping( )
	{
		alSourcei( src, AL_LOOPING, AL_FALSE );
		return this;
	}
	bool isPlaying()
	{
		ALint state;
		alGetSourcei( src, AL_SOURCE_STATE, &state );
		if ( state == AL_PLAYING )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void setPosition( float x, float y, float z )
	{
		pos[0] = x; pos[1] = y; pos[2] = z;
		alSourcefv(src, AL_POSITION, pos);
	}

	static void setListenerPos( float x, float y, float z )
	{
		listenerPos[0] = x;
		listenerPos[1] = y;
		listenerPos[2] = z;
		alListenerfv( AL_POSITION, listenerPos );
	}
	void enableSourceRelative()
	{
		alSourcei( src, AL_SOURCE_RELATIVE, AL_TRUE );
	}
	void disableSourceRelative()
	{
		alSourcei( src,  AL_SOURCE_RELATIVE, AL_FALSE );
	}

	void setVelocity( float x, float y, float z )
	{
		vel[0] = x; vel[1] = y; vel[2] = z;
		alSourcefv(src, AL_VELOCITY, vel );
	}

	
};


#endif