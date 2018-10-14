#include "KApplication.h"
#include "../helper/FileHelper.h"

namespace krk
{
	KApplication::KApplication() {}

	bool KApplication::Initialize()
	{
		bool initializedWithoutError = false;

		if (helper::FileExists(APP_SETTINGS_PATH))
		{
			initializedWithoutError = LoadSettings(mSettings);
		}
		else
		{
			initializedWithoutError = CreateDefaultSettings(mSettings);
		}

		return initializedWithoutError;
	}

	void KApplication::Run()
	{
		// Start the application
	}

	KApplication::~KApplication() {}
}
