
#include <stdio.h>
#include "ALSound.hpp"

ALfloat ALSound::listenerPos[3] = {0};

void ALSound::setListenerPos( float x, float y, float z )
{
	listenerPos[0] = x;
	listenerPos[1] = y;
	listenerPos[2] = z;
	alListenerfv( AL_POSITION, listenerPos );
}

ALSound::ALSound( const char *fname ): buf(0), src(0)
{
	alGenBuffers( 1, &buf );
	alGenSources( 1, &src );
	buf = alutCreateBufferFromFile( fname );
	if ( buf == AL_NONE )
	{
		printf("cannot load %s\n", fname );
	}
	alSourcei( src, AL_BUFFER, buf );
	alSourcei( src, AL_LOOPING, AL_FALSE );
}

ALSound::ALSound(): buf(0), src(0)
{
	alGenBuffers( 1, &buf );
	alGenSources( 1, &src );
}

ALSound* ALSound::load( const char *fname )
{
	buf = alutCreateBufferFromFile( fname );
	if ( buf == AL_NONE )
	{
		printf("cannot load %s\n", fname );
	}
	alSourcei( src, AL_BUFFER, buf );
	alSourcei( src, AL_LOOPING, AL_FALSE );
  return this;
}

ALSound::~ALSound()
{
	alDeleteBuffers( 1, &buf );
	alDeleteSources( 1, &src );
}

void ALSound::play()
{
	alSourcePlay( src );
}

void ALSound::stop()
{
	alSourceStop( src );
}

ALSound* ALSound::pause()
{
	alSourcePause( src );
	return this;
}

ALSound* ALSound::setVolume( float g )
{
	alSourcef( src, AL_GAIN, g );
	return this;
}

ALSound* ALSound::enableLooping( )
{
	alSourcei( src, AL_LOOPING, AL_TRUE );
	return this;
}

ALSound* ALSound::disableLooping( )
{
	alSourcei( src, AL_LOOPING, AL_FALSE );
	return this;
}

bool ALSound::isPlaying()
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

void ALSound::setPosition( float x, float y, float z )
{
	pos[0] = x; pos[1] = y; pos[2] = z;
	alSourcefv(src, AL_POSITION, pos);
}

void ALSound::enableSourceRelative()
{
	alSourcei( src, AL_SOURCE_RELATIVE, AL_TRUE );
}
void ALSound::disableSourceRelative()
{
	alSourcei( src,  AL_SOURCE_RELATIVE, AL_FALSE );
}

void ALSound::setVelocity( float x, float y, float z )
{
	vel[0] = x; vel[1] = y; vel[2] = z;
	alSourcefv(src, AL_VELOCITY, vel );
}

