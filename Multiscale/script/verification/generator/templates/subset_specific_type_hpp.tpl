#ifndef SUBSETSPECIFICTYPE_HPP
#define SUBSETSPECIFICTYPE_HPP

/******************************************************************************
{% for line in auto_generated_warning %}
 {{ line }}
{% endfor %}
 *****************************************************************************/


namespace multiscale {

    namespace verification {

        //! Enumeration for representing a specific subset type
        enum class SubsetSpecificType : unsigned int {
            {{ "%-33s"|format(spatial_entities[0].name|first_to_upper + "s") }} = 0,   /*!< {{ spatial_entities[0].name|first_to_upper }}s */
        {% for spatial_entity in spatial_entities[1:] %}
            {{ "%-33s"|format(spatial_entity.name|first_to_upper + "s") }}    ,   /*!< {{ spatial_entity.name|first_to_upper }}s */
        {% endfor %}
            {{ "%-33s"|format("NrOfSubsetSpecificTypeEntries") }}    ,   /*!< Enumeration type used to store the number of
            {{ "%-33s"|format(" ") }}             elements in the enumeration. Always leave it last! */
        };

    };

};


#endif
