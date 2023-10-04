# include <Controller.h>

Controller::Controller(Model &model, View &view) : _model(model), _view(view)
{
	srand(time(NULL));
	this->_input_vars.input = ' ';
	this->_input_vars.is_running = true;
	this->_model.load();
	this->_view.load();
	this->_input_thread = std::thread(Controller::inputThread, &this->_input_vars);
}

Controller::~Controller(void)
{
	this->_model.destroy();
	this->_view.destroy();
}

void Controller::exit(void)
{
	this->_input_vars.is_running_mutex.lock();
	this->_input_vars.is_running = false;
	this->_input_vars.is_running_mutex.unlock();
	this->_input_thread.join();
}

int Controller::updateModel(void)
{
	this->_model.updateSnek(this->_input_vars.input);
	int score = this->_model.updateMap();
	if (score != -1)
		this->_view.displayScore(score);
	return score;
}

void Controller::updateView(void)
{
	this->_view.update(this->_model.getMap());
}

void Controller::inputThread(t_input_vars *input_vars)
{
	input_vars->is_running_mutex.lock();
	while(input_vars->is_running)
	{
		input_vars->is_running_mutex.unlock();
		input_vars->input = getch();
		input_vars->is_running_mutex.lock();
	}
	input_vars->is_running_mutex.unlock();
}