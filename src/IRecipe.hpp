#ifndef IRECIPE_HPP
#define IRECIPE_HPP

#include <string>
#include <vector>

// Forward decls
struct IStep;
struct IPhoto;
struct IIngredient;
template <typename>
struct Quantity;

/**
 * Interface that represents a Recipe
 */
struct IRecipe {
    /**
     * Destructor
     */
    virtual ~IRecipe() {}

    /**
     * Gets the title
     *
     * @return std::string
     */
    virtual const std::string &getTitle() const = 0;

    /**
     * Gets the story
     *
     * @return std::string
     */
    virtual const std::string &getStory() const = 0;

    /**
     * Gets the list of steps that describe this recipe
     *
     * @return std::vector<IStep>
     */
    virtual const std::vector<IStep> &getSteps() const = 0;

    /**
     * Gets the cover photo of this recipe
     *
     * @return IPhoto
     */
    virtual const IPhoto &getCoverPhoto() const = 0;

    /**
     * Gets the list of ingredients required for this
     * recipe
     *
     * @return std::vector<IIngredient>
     */
    virtual const std::vector<IIngredient> &getIngredients() const = 0;
};

#endif /* IRECIPE_HPP */
