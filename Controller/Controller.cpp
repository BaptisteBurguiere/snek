# include <Controller.h>

Controller::Controller(Model &model, View &view) : _model(model), _view(view)
{
	srand(time(NULL));
	this->_model.load();
	this->_view.load();
	this->_view.drawMap();
}

Controller::~Controller(void)
{
	this->_model.destroy();
	this->_view.destroy();
}

int Controller::updateModel(char dir)
{
	this->_model.updateSnek(dir);
	int score = this->_model.updateMap();
	if (score != -1)
		this->_view.displayScore(score);
	return score;
}

void Controller::updateView(void)
{
	this->_view.update(this->_model.getMap());
}