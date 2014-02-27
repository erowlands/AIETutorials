#ifndef __DeferredRendering_H_
#define __DeferredRendering_H_

#include "Application.h"
#include "FBXFile.h"
#include <glm/glm.hpp>

// Derived application class that wraps up all globals neatly
class DeferredRendering : public Application
{
public:

	DeferredRendering();
	virtual ~DeferredRendering();

protected:
	struct BasicVertex
	{
		glm::vec4 position;
		glm::vec4 colour;
		glm::vec2 texCoord;
	};
	struct OGL_FBXRenderData
	{
		unsigned int VBO; // vertex buffer object
		unsigned int IBO; // index buffer object
		unsigned int VAO; // vertex array object
	};

	OGL_FBXRenderData m_ro;
	OGL_FBXRenderData m_quad;
	OGL_FBXRenderData m_lightQuad;

	FBXFile * m_fbx;

	glm::mat4 m_light;

	unsigned int m_FBO;
	unsigned int m_FBO_diffuse;
	unsigned int m_FBO_normal;
	unsigned int m_FBO_worldposition;
	unsigned int m_FBO_depth;

	unsigned int m_FBO_light;

	unsigned int m_geomPassShader;
	unsigned int m_quadShader;
	unsigned int m_LPPShader;

	void InitFBXSceneResource	(FBXFile *a_pScene );
	void UpdateFBXSceneResource	(FBXFile *a_pScene );
	void RenderFBXSceneResource	(FBXFile *a_pScene, 
									glm::mat4 a_view, 
									glm::mat4 a_projection);
	void DestroyFBXSceneResource(FBXFile *a_pScene );

	virtual bool onCreate(int a_argc, char* a_argv[]);
	virtual void onUpdate(float a_deltaTime);
	virtual void onDraw();
	virtual void onDestroy();

	glm::mat4	m_cameraMatrix;
	glm::mat4	m_projectionMatrix;
};

#endif // __DeferredRendering_H_