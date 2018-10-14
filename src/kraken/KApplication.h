#ifndef _K_APPLICATION_H_
#define _K_APPLICATION_H_

#include <QVector>

#include "KEditor.h"
#include "KTaskBar.h"
#include "KSettings.h"
#include "KProject.h"

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
		void Start(void);
		
		~KApplication(void);

	private:
		bool LoadAllProjects(void);


		KSettings mSettings;
		KEditor mEditor;
		KTaskBar mTaskBar;
		QVector<KProject> mProjects;
	};
}


#endif // _K_APPLICATION_H_
