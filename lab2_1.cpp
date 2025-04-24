#include <iostream>

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // 15a = (8 + 4 + 2 + 1)a = (a << 3) + (a << 2) + (a << 1) + a
    int part1 = (a << 3) + (a << 2) + (a << 1) + a;

    // 312b = (256 + 32 + 16 + 8)b = (b << 8) + (b << 5) + (b << 4) + (b << 3)
    int part2 = (b << 8) + (b << 5) + (b << 4) + (b << 3);

    // (15a + 312b) / 64 = (part1 + part2) >> 6
    int result1 = (part1 + part2) >> 6;

    // c * 120 = (64 + 32 + 16 + 8)c = (c << 6) + (c << 5) + (c << 4) + (c << 3)
    int result2 = (c << 6) + (c << 5) + (c << 4) + (c << 3);

    // d * 121 = (64 + 32 + 16 + 8 + 1)d = (d << 6) + (d << 5) + (d << 4) + (d << 3) + d
    int result3 = (d << 6) + (d << 5) + (d << 4) + (d << 3) + d;

    int result = result1 - result2 + result3;

    cout << "Result: " << result << endl;
    return 0;
}
