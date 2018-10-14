#ifndef _K_APPLICATION_H_
#define _K_APPLICATION_H_

#include "KEditor.h"
#include "KTaskBar.h"

namespace krk
{
	class KApplication
	{
	public:
		KApplication(void);

		KApplication(const KApplication& other) = delete;
		KApplication(KApplication&& other) = delete;
		KApplication& operator=(const KApplication& other) = delete;
		KApplication& operator=(KApplication&& other) = delete;

		~KApplication(void);

	private:
		void CreateDefaultSettings(void);
		void LoadSettings(void);


		KEditor mEditor;
		KTaskBar mTaskBar;
	};
}


#endif // _K_APPLICATION_H_
