/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe: function(new_val) {
            if (new_val === val) {
                return true;
            }
            throw new Error("Not Equal");
        },
        notToBe: function(new_val) {
            if (new_val !== val) {
                return true;
            }
            throw new Error("Equal");
        }
    };
};

/**
 * expect(5).toBe(5);         // { value: true }
 * expect(5).notToBe(5);      // throws "Equal"
 * expect(5).notToBe(6);      // { value: true }
 */
