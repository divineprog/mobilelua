// These functions are already defined as macros
// in the MoSync API and in order not get compile
// errors, we only use these declarations in the binding
// definitions used by tolua, not in the actual C-code.
// This file is never included in any C-code.

/**
 * Create an object the represents a size (width and height).
 * @param x The width value of the extent.
 * @param y The width value of the extent.
 * @return An extent object (a 32-bit int with x and y packed as 16-bit values).
 */
MAExtent EXTENT(int x, int y);

/**
 * Get the width part of an extent.
 * @param extent The extent object.
 * @return Width of the extent.
 */
int EXTENT_X(MAExtent extent);

/**
 * Get the height part of an extent.
 * @param extent The extent object.
 * @return Height of the extent.
 */
int EXTENT_Y(MAExtent extent);
