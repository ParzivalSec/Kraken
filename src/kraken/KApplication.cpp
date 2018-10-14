#include "KApplication.h"
#include "../helper/FileHelper.h"

namespace krk
{
	KApplication::KApplication() {}

	bool KApplication::Initialize()
	{
		bool initializedWithoutError = false;

		// Setup app settings (load or create)
		if (helper::FileExists(APP_SETTINGS_PATH))
		{
			initializedWithoutError = LoadSettings(mSettings);
		}
		else
		{
			initializedWithoutError = CreateDefaultSettings(mSettings);
		}

		// Setup active project (load if exists, otherwise open editor)


		return initializedWithoutError;
	}

	void KApplication::Start()
	{
		// Show either editor, or populate the sys-tray menu
	}

	KApplication::~KApplication() {}
}
