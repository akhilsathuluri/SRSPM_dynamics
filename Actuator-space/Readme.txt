Step-1: Run the SRSPM_actuator_space_dynamics.nb file
	Result: This process export all the coefficient matrices of the equations of motion into C++
		Files can be found in CPP/dyn_funcs_test.cpp and CPP/Cmat folder (except for the etavec function, which was copied from the eta function from the dyn_funcs.h file)

Step-2: Change directory to CPP and run make command
	Result: This gathers data for the process of free-fall of the moving platform and outputs all the generalised coordinate data

Parameters: The manipulator parameters can be changed in the Mathematica notebook (.nb) file and re-run to generate required C++ codes
	
