#include "KProject.h"

#include <QFileInfo>
#include <QTextStream>
#include <QUuid>

#include "../rapidjson/stringbuffer.h"
#include "../rapidjson/writer.h"
#include "../rapidjson/document.h"

namespace
{
	const char* DEFAULT_PROJECT_NAME = "New Project";
	const char* PROJECT_FILENAME_FORMAT = "%1.json"; // %1 == Filename UUID

	// Project JSON keys
	const char* PROJECT_NAME_KEY = "name";
}

namespace krk
{
	KProject CreateNewProject()
	{
		QUuid projectUUID = QUuid::createUuid();

		return KProject 
		{ 
			DEFAULT_PROJECT_NAME, 
			QString(PROJECT_FILENAME_FORMAT).arg(projectUUID.toString()) 
		};
	}

	bool LoadProject(const char* path, KProject& project)
	{
		// Load data from file at project.path
		QFile projectFile(path);
		if (!projectFile.open(QIODevice::ReadOnly))
		{
			return false;
		}

		QTextStream inputStream(&projectFile);
		QString fileContent = inputStream.readAll();

		rapidjson::Document jsonDocument;

		jsonDocument.Parse(fileContent.toUtf8().constData());
		assert(jsonDocument.IsObject() && "Top-level json was no object!");
		assert(jsonDocument.HasMember(PROJECT_NAME_KEY) && "Parsed content does not include the name property!");

		project.name = jsonDocument[PROJECT_NAME_KEY].GetString();
		project.path = path;
		// TODO: Load other members (commands, variables, categories)

		return true;
	}

	bool SaveProject(const KProject& project)
	{
		// Store everything to file at project.path
		rapidjson::StringBuffer buffer;
		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

		writer.StartObject();
			writer.Key(PROJECT_NAME_KEY);
			writer.String(project.name.toUtf8().constData());
			// TODO: Write commands, variables and categories arrays
		writer.EndObject();

		QFile projectFile(project.path);
		if (projectFile.open(QIODevice::ReadWrite))
		{
			QTextStream outputStream(&projectFile);
			outputStream << buffer.GetString() << '\n';
			return true;
		}

		return false;
	}

	bool DeleteProject(const KProject& project)
	{
		// Delete file at project.path
		QFile projectFile(project.path);
		return projectFile.remove();
	}
}
