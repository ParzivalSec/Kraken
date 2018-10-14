--
-- We use the premake-qt plugin to manage QT settings
--
require("premake-qt/qt")
local qt = premake.extensions.qt

workspace "Kraken"
	location("workspace/" .. _ACTION) -- a unique dir for every differen project solution
	configurations { "Debug", "Release" }
	platforms { "Win64", "Linux", "MacOS" }
	
	filter { "platforms:Win64" }
		system "Windows"
		architecture "x64"
	
	filter {}
	
	flags { "ShadowedVariables", "UndefinedIdentifiers" }
	
project "Kraken"
	kind "ConsoleApp"
	language "C++"
	targetname "kraken"
	targetdir "build/kraken/%{cfg.buildcfg}"
	
	files { "src/**.h", "src/**.cpp", "src/**.ui", "src/**.qrc" }

	qt.enable()
	qtmodules { "core", "gui", "widgets", "opengl" }
	qtprefix "Qt5"
	
	filter "configurations:Debug"
        symbols "On"
        flags { "StaticRuntime" }
		qtsuffix "d"
		debugdir "build"
		
    filter "configurations:Release"
		symbols "Off"
        flags { "StaticRuntime" }
		optimize "Full"
		debugdir "build"
	
-- Create a custom clean action
newaction {
    trigger = "clean",
    description = "clean the workspace folder",
    execute     = function () 
        print "Remove artifacts and ./workspaces/*"
        os.rmdir "./workspaces"
        os.rmdir "./build"
        print "Finished cleanup!"
    end
}