#include "qapplication.h"
#include "ui_KrakenEditor.h"
#include "kraken/KApplication.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	krk::KApplication krakenApp;

	// --> KrakenApplication:
	// 1. Load AppSettings.ini and all projects in the project folder
	// 2. Check if there is any active project -> if there is, create taskbar menu for that project
	// 3. Otherwise open up the project editor 

	// --> KrakenEditor
	// 1. Display list of all projects
	// 2. On selection, display commands, variables and categories of that project
	// 3. CRUD for each of the entities

	// -->KrakenTaskBar
	// 1. General option to select the currently active project (if there are any)
	// 2. Level-1 menus for the different categories, which expand to the commands they hold (beside the added icons?)
	// 3. Category-less commands are on the same level as other categories
	// 4. Option to close the application (Exit)

	if (krakenApp.Initialize())
	{
		krakenApp.Run();
		
		QWidget *widget = new QWidget;
		Ui::KrakenEditor ui;
		ui.setupUi(widget);

		widget->show();
	}
	else
	{
		// TODO: Display error prompt to the user that the app was not able to initialize
	}

	return QApplication::exec();
}

