#ifndef _TSINKSPLASH_H_
#define _TSINKSPLASH_H_

#include "..\SoundService\VSoundService.h"
#include "CVECTOR.h"
#include "dx8render.h"
#include "exs.h"
#include "geos.h"
#include "matrix.h"
#include "messages.h"
#include "model.h"
#include "sea_base.h"
#include "seps.h"

///////////////////////////////////////////////////////////////////
// CLASS DEFINITION
///////////////////////////////////////////////////////////////////
struct SINK_VERTEX
{
    CVECTOR pos;
    dword color;
    float tu, tv;
};

class TSinkSplash
{
  public:
    TSinkSplash();
    virtual ~TSinkSplash();

    void Initialize(INIFILE *_ini, SEA_BASE *sea);
    void Release();
    void Start(const CVECTOR &_pos, WORD *_indexes, SINK_VERTEX *_vertexes, long vOffset);
    void Process(dword _dTime, WORD *_indexes, SINK_VERTEX *_vertexes);
    bool Enabled();
    void Reset(WORD *_indexes, SINK_VERTEX *_vertexes);
    void AdditionalRealize(dword _dTime);

  private:
    float HeightF(dword _time, float _r, float _k);

    SEPS_PS *ps;
    bool enabled;
    SEA_BASE *sea;
    dword time;

    float distortDivider;
    CVECTOR center, dir;
    float growK;
};

#endif