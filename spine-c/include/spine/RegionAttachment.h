/******************************************************************************
 * Spine Runtime Software License - Version 1.0
 * 
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms in whole or in part, with
 * or without modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. A Spine Single User License or Spine Professional License must be
 *    purchased from Esoteric Software and the license must remain valid:
 *    http://esotericsoftware.com/
 * 2. Redistributions of source code must retain this license, which is the
 *    above copyright notice, this declaration of conditions and the following
 *    disclaimer.
 * 3. Redistributions in binary form must reproduce this license, which is the
 *    above copyright notice, this declaration of conditions and the following
 *    disclaimer, in the documentation and/or other materials provided with the
 *    distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#ifndef SPINE_REGIONATTACHMENT_H_
#define SPINE_REGIONATTACHMENT_H_

#include <spine/Attachment.h>
#include <spine/Atlas.h>
#include <spine/Slot.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	VERTEX_X1 = 0, VERTEX_Y1, VERTEX_X2, VERTEX_Y2, VERTEX_X3, VERTEX_Y3, VERTEX_X4, VERTEX_Y4
} VertexIndex;

typedef struct RegionAttachment RegionAttachment;
struct RegionAttachment {
	Attachment super;
	float x, y, scaleX, scaleY, rotation, width, height;

	void* rendererObject;
	int regionOffsetX, regionOffsetY; /* Pixels stripped from the bottom left, unrotated. */
	int regionWidth, regionHeight; /* Unrotated, stripped pixel size. */
	int regionOriginalWidth, regionOriginalHeight; /* Unrotated, unstripped pixel size. */

	float offset[8];
	float uvs[8];
};

RegionAttachment* RegionAttachment_create (const char* name);
void RegionAttachment_setUVs (RegionAttachment* self, float u, float v, float u2, float v2, int/*bool*/rotate);
void RegionAttachment_updateOffset (RegionAttachment* self);
void RegionAttachment_computeWorldVertices (RegionAttachment* self, float x, float y, Bone* bone, float* vertices);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_REGIONATTACHMENT_H_ */
