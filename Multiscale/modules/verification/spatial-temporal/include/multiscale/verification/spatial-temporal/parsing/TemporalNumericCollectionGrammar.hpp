#ifndef TEMPORALNUMERICCOLLECTIONGRAMMAR_HPP
#define TEMPORALNUMERICCOLLECTIONGRAMMAR_HPP

#include "multiscale/verification/spatial-temporal/attribute/TemporalNumericCollectionAttribute.hpp"
#include "multiscale/verification/spatial-temporal/parsing/BinaryNumericMeasureGrammar.hpp"
#include "multiscale/verification/spatial-temporal/parsing/ChangeMeasureGrammar.hpp"
#include "multiscale/verification/spatial-temporal/parsing/PrimaryNumericMeasureGrammar.hpp"
#include "multiscale/verification/spatial-temporal/parsing/SymbolTables.hpp"
#include "multiscale/verification/spatial-temporal/parsing/UnaryNumericMeasureGrammar.hpp"

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/spirit/include/qi_and_predicate.hpp>

#include <string>


namespace multiscale {

    namespace verification {

        // Namespace aliases
        namespace phoenix = boost::phoenix;
        namespace qi = boost::spirit::qi;


        //! The grammar for parsing temporal numeric collection statements
        template <typename Iterator>
        class TemporalNumericCollectionGrammar
            : public qi::grammar<Iterator, TemporalNumericCollectionAttribute(), qi::space_type> {

            private:

                // Grammars

                std::shared_ptr<SpatialMeasureCollectionGrammar<Iterator>>
                    spatialMeasureCollectionGrammar;               /*!< The grammar for parsing spatial measure
                                                                        collection which will be passed by reference
                                                                        to the primary numeric measure grammar */

                std::shared_ptr<PrimaryNumericMeasureGrammar<Iterator>>
                    primaryNumericMeasureRule;                      /*!< The grammar for parsing primary numeric
                                                                         measures */
                UnaryNumericMeasureGrammar<Iterator>
                    unaryNumericMeasureRule;                        /*!< The grammar for parsing unary numeric
                                                                         measures */
                BinaryNumericMeasureGrammar<Iterator>
                    binaryNumericMeasureRule;                       /*!< The grammar for parsing binary numeric
                                                                         measures */

                ChangeMeasureGrammar<Iterator>
                    changeMeasureRule;                              /*!< The grammar for parsing change measures */

                // Rules

                qi::rule<Iterator, TemporalNumericCollectionAttribute(), qi::space_type>
                    temporalNumericCollectionRule;                  /*!< The rule for parsing temporal numeric
                                                                         collections */
                qi::rule<Iterator, TemporalNumericMeasureCollectionAttribute(), qi::space_type>
                    temporalNumericMeasureCollectionRule;           /*!< The rule for parsing temporal numeric measure
                                                                         collections */
                qi::rule<Iterator, ChangeTemporalNumericCollectionAttribute(), qi::space_type>
                    changeTemporalNumericCollectionRule;            /*!< The rule for parsing a change temporal numeric
                                                                         collections attribute */
                qi::rule<Iterator, TimeseriesTimeseriesComponentAttribute(), qi::space_type>
                    timeseriesTimeseriesComponentRule;              /*!< The rule for parsing a timeseries timeseries
                                                                         component attribute */
                qi::rule<Iterator, HomogeneousHomogeneousTimeseriesAttribute(), qi::space_type>
                    homogeneousHomogeneousTimeseriesRule;           /*!< The rule for parsing a homogeneous homogeneous
                                                                         timeseries measure attribute */

                qi::rule<Iterator, TimeseriesMeasureAttribute(), qi::space_type>
                    timeseriesMeasureRule;                          /*!< The rule for parsing a timeseries measure */
                qi::rule<Iterator, HomogeneousTimeseriesMeasureAttribute(), qi::space_type>
                    homogeneousTimeseriesMeasureRule;               /*!< The rule for parsing a homogeneous timeseries
                                                                         measure */

                qi::rule<Iterator, TimeseriesComponentAttribute(), qi::space_type>
                    timeseriesComponentRule;                        /*!< The rule for parsing a timeseries
                                                                         component */
                qi::rule<Iterator, HeterogeneousTimeseriesComponentAttribute(), qi::space_type>
                    heterogeneousTimeseriesComponentRule;           /*!< The rule for parsing a heterogeneous
                                                                         timeseries component */
                qi::rule<Iterator, HomogeneousTimeseriesComponentAttribute(), qi::space_type>
                    homogeneousTimeseriesComponentRule;             /*!< The rule for parsing a homogeneous timeseries
                                                                         component */

                qi::rule<Iterator, NumericMeasureAttribute(), qi::space_type>
                    numericMeasureRule;                             /*!< The rule for parsing a numeric measure */
                qi::rule<Iterator, UnaryNumericNumericAttribute(), qi::space_type>
                    unaryNumericNumericRule;                        /*!< The rule for parsing a unary numeric numeric
                                                                         attribute */
                qi::rule<Iterator, BinaryNumericNumericAttribute(), qi::space_type>
                    binaryNumericNumericRule;                       /*!< The rule for parsing a binary numeric numeric
                                                                         attribute */

                // Enumeration parsers

                TimeseriesMeasureTypeParser
                    timeseriesMeasureTypeParser;                    /*!< The timeseries measure type parser */
                HomogeneousTimeseriesMeasureTypeParser
                    homogeneousTimeseriesMeasureTypeParser;         /*!< The homogeneous timeseries measure type
                                                                         parser */

                HeterogeneousTimeseriesComponentTypeParser
                    heterogeneousTimeseriesComponentTypeParser;     /*!< The heterogeneous timeseries component type
                                                                         parser */
                HomogeneousTimeseriesComponentTypeParser
                    homogeneousTimeseriesComponentTypeParser;       /*!< The homogeneous timeseries component type
                                                                         parser */

            public:

                TemporalNumericCollectionGrammar();

            private:

                //! Initialisation function
                void initialise();

                //! Initialise the grammar
                void initialiseGrammar();

                //! Initialise the temporal numeric collection rule
                void initialiseTemporalNumericCollectionRule();

                //! Initialise the timeseries measure rule
                void initialiseTimeseriesMeasureRule();

                //! Initialise the timeseries component rule
                void initialiseTimeseriesComponentRule();

                //! Initialise the numeric measure rule
                void initialiseNumericMeasureRule();

                //! Initialise debug support
                void initialiseDebugSupport();

                //! Assign names to the rules
                void assignNamesToRules();

                //! Assign names to the temporal numeric collection rule
                void assignNamesToTemporalNumericCollectionRules();

                //! Assign names to the timeseries measure rule
                void assignNamesToTimeseriesMeasureRules();

                //! Assign names to the timeseries component rule
                void assignNamesToTimeseriesComponentRules();

                //! Assign names to the numeric measure rules
                void assignNamesToNumericMeasureRules();

                //! Initialise the debugging of rules
                void initialiseRulesDebugging();

                //! Initialise debugging for the temporal numeric collection rule
                void initialiseTemporalNumericCollectionRuleDebugging();

                //! Initialise debugging for the timeseries measure rule
                void initialiseTimeseriesMeasureRuleDebugging();

                //! Initialise debugging for the timeseries component rule
                void initialiseTimeseriesComponentRuleDebugging();

                //! Initialise debugging for the numeric measure rule
                void initialiseNumericMeasureRuleDebugging();

                //! Initialise the error handling routines
                void initialiseErrorHandlingSupport();

                //! Initialise the temporal numeric collection error handling support
                void initialiseTemporalNumericCollectionErrorHandlingSupport();

                //! Initialise the numeric measure error handling support
                void initialiseNumericMeasureErrorHandlingSupport();

        };

    };

};


#endif
