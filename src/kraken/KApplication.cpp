#include "KApplication.h"

#include "../helper/FileHelper.h"

namespace
{
	const char* APP_SETTINGS_PATH = "./app_settings.ini";
}

namespace krk
{
	KApplication::KApplication()
	{
		if (helper::FileExists(APP_SETTINGS_PATH))
		{
			LoadSettings();
		}
		else
		{
			CreateDefaultSettings();
		}
	}

	KApplication::~KApplication()
	{
	}

	void KApplication::CreateDefaultSettings()
	{
	}

	void KApplication::LoadSettings()
	{
	}
}