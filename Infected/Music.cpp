#include "Music.h"

Music::Music()
	:mRd(), mMt(mRd()), distribution(mSongs.size()), mWhatFile(distribution(mMt))
{
	mSongs[0] = "Music/[HighQuality]ShadowoftheColossusOST25-ADespair-filledFarewell.ogg";
	mSongs[1] = "Music/CorpsePartyBloodCoveredOST-Chapter 1'sMainTheme(Extended).ogg";
	mSongs[2] = "Music/IceFlow.ogg";
	mSongs[3] = "Music/JohnnyGhosst-Stopitft.PG(VisualsbyThatsBvnk).ogg";
	mSongs[4] = "Music/LovingYouremixfeat.InfectedMonsta(VisualsbyThatsBVNK)iBerleezyVRchatsong.ogg";
	mSongs[5] = "Music/PromiseReprise(PianoVersion)-SilentHill2[HQ].ogg";
	mSongs[6] = "Music/Rhinoceros.ogg";
	mSongs[7] = "Music/JohnnyGhosst-SumLoveFeat.PGakaInfectedMonsta(VisualsbyThatsBVNK).ogg";
	mSongs[8] = "Music/SadPianoMusic-Isolation(OriginalComposition).ogg";
	mSongs[9] = "Music/VolatileReaction.ogg";
}

void Music::Play()
{
	mWhatFile = distribution(mMt);

	mMusic.openFromFile(mSongs.at(mWhatFile));

	mMusic.play();

}
