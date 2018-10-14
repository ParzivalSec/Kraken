#ifndef _K_APPLICATION_H_
#define _K_APPLICATION_H_

#include "KEditor.h"
#include "KTaskBar.h"
#include "KSettings.h"

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

		bool Initialize(void);
		void Run();
		
		~KApplication(void);

	private:
		KSettings mSettings;
		KEditor mEditor;
		KTaskBar mTaskBar;
	};
}


#endif // _K_APPLICATION_H_
