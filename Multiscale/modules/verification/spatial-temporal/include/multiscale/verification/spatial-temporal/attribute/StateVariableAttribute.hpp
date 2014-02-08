#ifndef STATEVARIABLEATTRIBUTE_HPP
#define STATEVARIABLEATTRIBUTE_HPP

//#include "multiscale/verification/spatial-temporal/attribute/Attribute.hpp"

#include <boost/fusion/include/adapt_struct.hpp>
#include <string>


namespace multiscale {

	namespace verification {

		//! Class for representing a state variable attribute
		class StateVariableAttribute {
//		class StateVariableAttribute : public Attribute {

			public:

				std::string name;

//				//! Evaluate the constraint
//				bool evaluate() const override {
//					return (name.compare("T") == 0);
//				}

		};

	};

};


BOOST_FUSION_ADAPT_STRUCT(
    multiscale::verification::StateVariableAttribute,
    (std::string, name)
)

#endif
