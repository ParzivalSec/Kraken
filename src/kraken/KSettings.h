#ifndef _K_SETTINGS_H_
#define _K_SETTINGS_H_

#include <QString>

namespace krk
{
	extern const char* APP_SETTINGS_PATH;

	struct KSettings
	{
		QString activeProject;
	};

	bool CreateDefaultSettings(KSettings& setting);
	bool LoadSettings(KSettings& settings);
}

#endif // _K_SETTINGS_H_
