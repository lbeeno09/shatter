#include "AppBase.h"

class App : public AppBase
{
public:
	App();

	~App();

	void init() override;

	void update() override;

private:
	// Our state
	bool showDemoWindow_;
	bool showAnotherWindow_;
};