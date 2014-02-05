#ifndef PARSERGRAMMAR_HPP
#define PARSERGRAMMAR_HPP

#include "multiscale/verification/spatial-temporal/attribute/SynthesizedAttribute.hpp"
#include "multiscale/verification/spatial-temporal/exception/ParserGrammarUnexpectedTokenException.hpp"
#include "multiscale/verification/spatial-temporal/handler/ErrorHandler.hpp"

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/spirit/include/qi_and_predicate.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


namespace multiscale {

    namespace verification {

    	// Namespace aliases
		namespace phoenix = boost::phoenix;
		namespace qi = boost::spirit::qi;
		namespace ascii = boost::spirit::ascii;

		// Create a lazy error handler function
		phoenix::function<ErrorHandler> const handleError = ErrorHandler();

        //! The grammar for parsing (P)BLSTL spatial-temporal logical queries
        template <typename Iterator>
        class ParserGrammar : public qi::grammar<Iterator, ConstraintAttribute(), ascii::space_type> {

            private:

                qi::rule<Iterator, ConstraintAttribute(), ascii::space_type> 			constraintRule;				/*!< The rule for parsing a constraint */
                qi::rule<Iterator, UnaryConstraintAttribute(), ascii::space_type> 		unaryConstraintRule;		/*!< The rule for parsing a unary constraint */
                qi::rule<Iterator, NotConstraintAttribute(), ascii::space_type> 		notConstraintRule;			/*!< The rule for parsing a "not" constraint */
                qi::rule<Iterator, NumericStateVariableAttribute(), ascii::space_type> 	numericStateVariableRule;	/*!< The rule for parsing a numeric state variable */
                qi::rule<Iterator, StateVariableAttribute(), ascii::space_type> 		stateVariableRule;			/*!< The rule for parsing a state variable */
                qi::rule<Iterator, std::string(), ascii::space_type> 					stringRule; 				/*!< The rule for parsing a string without escaping white space */

            public:

                ParserGrammar() : ParserGrammar::base_type(constraintRule) {
                	// Rules definitions

                	constraintRule
                		=	unaryConstraintRule >> *( 'V' > unaryConstraintRule)
                		|	'(' > constraintRule > ')';

                	unaryConstraintRule
						=	notConstraintRule
						|	numericStateVariableRule;

                	notConstraintRule
                		=	'~' > constraintRule;

                	numericStateVariableRule
                		=   stateVariableRule;

                	stateVariableRule
                		=	stringRule;

                	stringRule
                		=	+(qi::char_("a-zA-UW-Z_"));

                	// Assign a name to the rules
					constraintRule.name("constraintRule");
					unaryConstraintRule.name("unaryConstraintRule");
					notConstraintRule.name("notConstraintRule");
					numericStateVariableRule.name("numericStateVariableRule");
					stateVariableRule.name("stateVariableRule");
					stringRule.name("stringRule");

					// Debugging and reporting support
					debug(constraintRule);
					debug(unaryConstraintRule);
					debug(notConstraintRule);
					debug(numericStateVariableRule);
					debug(stateVariableRule);
					debug(stringRule);

                	// Error handling routines
                	qi::on_error<qi::fail>(constraintRule, multiscale::verification::handleError(qi::_4, qi::_3, qi::_2));
                	qi::on_error<qi::fail>(unaryConstraintRule, multiscale::verification::handleError(qi::_4, qi::_3, qi::_2));
                	qi::on_error<qi::fail>(notConstraintRule, multiscale::verification::handleError(qi::_4, qi::_3, qi::_2));
                }

        };

    };

};

#endif
