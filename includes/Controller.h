#ifndef CONTROLLER_H
# define CONTROLLER_H

# include <Model.h>
# include <View.h>
# include <cstdlib>
# include <time.h>
# include <thread>
# include <mutex>

class Controller
{
	public:
		Controller(Model &model, View &view);
		~Controller(void);

		void updateView(void);
		int updateModel(void);
		void exit(void);

		typedef struct s_input_vars
		{
			char input;
			// std::mutex input_mutex;
			bool is_running;
			std::mutex is_running_mutex;
		} t_input_vars;

	private:
		Model _model;
		View _view;
		t_input_vars _input_vars;
		std::thread _input_thread;

		static void inputThread(t_input_vars *input_vars);
};


#endif