#ifndef IMPLICATIONATTRIBUTE_HPP
#define IMPLICATIONATTRIBUTE_HPP

#include "multiscale/verification/spatial-temporal/attribute/LogicPropertyAttribute.hpp"

using namespace multiscale::verification;


namespace multiscale {

	namespace verification {

		//! Structure for representing an implication attribute
		struct ImplicationAttribute {
			LogicPropertyAttribute lhsLogicalProperty;
			LogicPropertyAttribute rhsLogicalProperty;
		};

	};

};


BOOST_FUSION_ADAPT_STRUCT(
    multiscale::verification::ImplicationAttribute,
    (LogicPropertyAttribute, lhsLogicalProperty)
    (LogicPropertyAttribute, rhsLogicalProperty)
)

#endif
