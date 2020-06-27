#include "bdd-for-c.h"

spec("some feature") {

    // These variable definitions must be static because each test
    // section (it / before / etc...) is a separate function call
    // and thus will just overwrite these otherwise.
    static int a;
    static int b;

    after_each() {
        b = 3;
    }

    describe("sub-feature 1") {
        it("should not work") {
            a = 2;
            b = 2;
            check(a + b == 6, "Adding %i to %i did not equal %i", a, b, 6);
        }
        it("should work") {
            check(a + b == 6);
        }
    }

    describe("sub-feature 2") {
        context("when a is set to 2") {
            before_each() {
                a = 2;
            }
            it("should equal to 5") {
                check(a + b == 5);
            }
        }
    }
    describe("when there's a failure in a post-condition") {
        after_each() {
            check(a + b == 6, "Adding %i to %i did not equal %i", a, b, 6);
        }
        it("should equal to 6") {
            a = 4;
        }
    }

    before_each() {
        a = 3;
    }

    before() {
        a = 3;
        b = 3;
    }
}
