#ifndef __Json_H__
#define __Json_H__
#include <stdio.h>
#include <json-c/json.h>
void Json(const char *path, char *mode);
/** Delete the given json_object field
 *
 * The reference count will be decremented for the deleted object.  If there
 * are no more owners of the value represented by this key, then the value is
 * freed.  Otherwise, the reference to the value will remain in memory.
 *
 * @param path the json_object instance
 * @param mode the object field name
 * @returns whether or not the key exists
 */
#endif