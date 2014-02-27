The Academy of Interactive Entertainment's Second Year Framework 2014

Purpose:

	A minimal framework for creating OpenGL-based applications for use in class exercises and tutorials. 
	Its aim is to allow a programmer to create a program that supports rendering as quick as possible while 
	also keeping the pre-made code small. Basic support for a window and input is provided through the use 
	of third-party open-source libraries.
	
	Also includes an FBX loader project that is pre-built to reduce the user's need to install the FBX SDK from Autodesk.
	
	Includes a Project Template for Microsoft's Visual Studio 2012 to further increase the speed of project creation.

	Currently supported OS: Windows 7 and OSX 10.8.
	Currently supported IDEs: Visual Studio 2010, Visual Studio 2012, and Xcode 5.
	
	Requires OpenGL 3.2 as a minimum.

Structure:

	- Folder Root:
		- 3rdParty	// third-party libraries (glfw, glew, glm, soil)
		- Build		// "release" folder containing assets (images, shaders, models, etc)
		- Include	// headers for the framework (application, utilities, gizmos)
		- Lib		// folder to contain the libraries when built (contains pre-built FBXLoader)
		- Projects	// contains the framework's solution/workspace and subfolders for each project
		- Source	// source code for the framework (application, utilities, gizmos)
		- Tools		// additional tools, including an FBX loader library
		
	The framework makes use of the following third-party open-source libraries:
	
		- glfw:	OpenGL FrameWork to support cross-platform window creation and input
		- glew:	OpenGL Extension Wrangler to minimise OpenGL setup fuss
		- glm:	OpenGL Math library that mimics GLSL math
		- soil:	Simple OpenGL Image Library supports loading standard game images (bmp,tga,png,dds)

Project Template Install:

	Windows + Microsoft's Visual Studio 2012:

		Copy the ./Tools/AIE_vs2012_ProjectTemplate.zip file to C:/Users/<username>/Documents/Visual Studio 2012/Templates/ProjectTemplates/Visual C++ Project/
	
Build:

	Microsoft's Visual Studio 2012:

		Open the AIE_vs2012.sln file located in ./Projects/
		The solution will include the AIEFramework project. Add a new Project to the solution and select the AIEApplication as the project type (must install the project template first).
		The project will be created within the ./Projects/ folder. Set the new project to the StartUp Project and compile/run. Ensure that the AIEFramework project is compiled first.
		Additionally you can set the new project to depend on the AIEFramework project to ensure the framework is compiled first.

		Your newly created project will link in the AIEFramework.lib and an FBXLoader.lib. The FBXLoader is an additional project that is not included in the solution by default as it	depends on the Autodesk FBX SDK being installed. As the library is prebuilt you shouldn't need the SDK installed.
		
	Microsoft's Visual Studio 2010:

		Open the AIE_vs2010.sln file located in ./Projects/
		The solution will include the AIEFramework project.
		Create a new Win32 Console Application project within the ./Projects/ folder. Set the new project to the StartUp Project.
		Ensure that the AIEFramework project is compiled first.
		Additionally you can set the new project to depend on the AIEFramework project to ensure the framework is compiled first.
		
		Link the new project to AIEFramework library (AIEFramework.lib for release, AIEFramework_d.lib for debug).
		Add the ./Lib/vs2010 folder to linker directories.
		Add the ./Include folder to include directories.
		Also add the 3rdParty include directories (./3rdParty/glm, ./3rdParty/glew/include, ./3rdParty/glfw/include, ./3rdParty/soil/src).
		Add the following preprocessor defines: GLEW_STATIC GLM_SWIZZLE GLM_FORCE_RADIANS.
		To include FBX loading link with the FBXLoader library (FBXLoader.lib for release, FBXLoader_d.lib for debug).
		
		Create a class that derives from Application ad implement the pure virtual functions (i.e. onCreate(), onDraw() etc).
		Create a main that creates a new instance of your derived class. Call the create() method, checking its return for success.
		If create() succeeds then call the run() method. run() will start a continuous loop that returns once the application has finished running.
		Once run() returns you can destroy your application instance and return from main.
		
	Apple XCode 5:
	
		Open the AIE_xcode.xcworkspace workspace located in ./Projects
		The workspace will include the AIEFramework project.
		Add a new Command Line Tool project to the workspace within the ./Projects folder.
		
		XCode projects require a little more setup than Visual Studio. You need to link your project with Cocoa.framework, IOKit.framework, OpenGL.framework, the libFBXLoader.a located within the ./Lib/xcode folder, and also link with the AIEFramework project's output, libAIEFramework.a.
		This should automaticall add the linker search paths.
		
		Add the include search paths for ./Include, and also the 3rd party directories ((./3rdParty/glm, ./3rdParty/glew/include, ./3rdParty/glfw/include, ./3rdParty/soil/src).
		Add the following preprocessor defines: GLEW_STATIC GLM_SWIZZLE GLM_FORCE_RADIANS.
		
		Also you must set the "Apple LLVM 5.0 - Language - C++" C++ Standard Library option to "libstdc++ (GNU C++ standard library).

		Create a class that derives from Application ad implement the pure virtual functions (i.e. onCreate(), onDraw() etc).
		Create a main that creates a new instance of your derived class. Call the create() method, checking its return for success.
		If create() succeeds then call the run() method. run() will start a continuous loop that returns once the application has finished running.
		Once run() returns you can destroy your application instance and return from main.
		
		You may also need to set the working directory for XCode. This is located under your new projects scheme, accessable via the menu option "Product->Scheme->Edit Scheme". The working directory can be set in the "Run->Options" panel.