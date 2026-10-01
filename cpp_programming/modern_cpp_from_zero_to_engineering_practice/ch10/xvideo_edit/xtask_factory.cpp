#include "xtask_factory.h"
#include "fftask.h"
#include <iostream>
std::unique_ptr<XTask> XTaskFactory::Create(int type)
{
	switch (type)
	{
	case 0:
		return std::make_unique<FFTask>();
	default:
		std::cerr << "XTask type :"
			<< type << " not support!" << std::endl;
		break;
	}
	return nullptr;
}