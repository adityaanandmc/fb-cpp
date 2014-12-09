#ifndef ISTEP_HPP
#define ISTEP_HPP

#include <string>
#include <vector>

// Forward decls
struct IPhoto;

struct IStep {
    /**
     * Destructor
     */
    virtual ~IStep() {}

    /**
     * Gets the position of the step in the
     * recipe it belongs to
     *
     * @return uint8_t
     */
    virtual const uint8_t &getPosition() const = 0;

    /**
     * Gets the content of the step
     *
     * @return std::string
     */
    virtual const std::string &getContent() const = 0;

    /**
     * Gets the collection of images which describe
     * the content of this step
     *
     * @return std::vector<IPhoto>
     */
    virtual const std::vector<IPhoto> &getImages() const = 0;
};

#endif /* ISTEP_HPP */
