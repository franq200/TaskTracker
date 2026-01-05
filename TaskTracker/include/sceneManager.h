#pragma once
#include <memory>
#include "IScene.h"

class sceneManager {
public:
	sceneManager();
	~sceneManager();
private:
	std::unique_ptr<IScene> currentScene_;
};

