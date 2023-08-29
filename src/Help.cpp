#include <iostream>

void printHelp(bool helpRotor, bool helpReflector, bool helpAttack) {

    if (helpRotor) {
        std::cout << "Rotor option:\n"  
              << "                          -n, --rotor-number <number of rotors to try> \n"
              << "\n"
              << "The default value is 5 (meaning rotors I, II, III, IV and V will be tested)\n"
              << "A number between 3 and 8 (included) can be given\n"
              << "\n"
              << "Available rotors:\n"
              << "\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |  option  |             wiring              |   notch   |  date introduced   |        model name        |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    I     |   EKMFLGDQVZNTOWYHXUSPAIBRCJ    |     Q     |        1930        |   Enigma I (Wehrmacht)   |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    II    |   AJDKSIRUXBLHWTMCQGZNPYFVOE    |     E     |        1930        |   Enigma I (Wehrmacht)   |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    III   |   BDFHJLCPRTXVZNYEIWGAKMUSQO    |     V     |        1930        |   Enigma I (Wehrmacht)   |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    IV    |   ESOVPZJAYQUIRHXLNFTGKDCMWB    |     J     |   December 1938    |         M3 Army          |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    V     |   VZBRGITYUPSDNHLXAWMJQOFECK    |     Z     |   December 1938    |         M3 Army          |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    VI    |   JPGVOUMFYQBENHZRDKASXLICTW    |    Z+M    |        1939        | M3 & M4 Naval (FEB 1942) |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    VII   |   NZJHGRCXMYSWBOUFAIVLPEKQDT    |    Z+M    |        1939        | M3 & M4 Naval (FEB 1942) |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    VIII  |   FKQHTLXOCBJSPDZRAMEWNIUYGV    |    Z+M    |        1939        | M3 & M4 Naval (FEB 1942) |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "\n";
    }
    else if (helpReflector) {
        std::cout << "Reflector option usage: -R, --reflector <wiring>\n"
              << "\n"
              << "If no reflector is specified the default one is B\n"
              << "Option:\n"
              << "  <wiring>                                            Specify the internal wiring of the rotor\n"
              << "\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "  |  option  |             wiring              |  date introduced   |        model name        |\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "  |    A     |   EJMZALYXVBWFCRQUONTSPIKHGD    |         x          |            x             |\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "  |    B     |   YRUHQSLDPXNGOKMIEBFZCWVJAT    |         x          |            x             |\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "  |    C     |   FVPJIAOYEDRZXWGCTKUQSBNMHL    |         x          |            x             |\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "  |  B-Thin  |   ENKQAUYWJICOPBLMDXZVFTHRGS    |        1940        |     M4 R1 (M3 + Thin)    |\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "  |  C-Thin  |   RDOBJNTKVEHMLFCWZAXGYIPSUQ    |        1940        |     M4 R1 (M3 + Thin)    |\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "\n"
              << "Examples:             enigma -R A \n"
              << "\n"
              << "is equivalent to      enigma --reflector A\n";
    }
    else {
        std::cout << "Usage: ioc-attack [-r/-p] [options]\n"
                << "Options:\n"
                << "  -h, --help <rotor|reflector|attack>                       Display help message\n"
                << "  -n, --rotor-number <number of rotors to try>              Specify the number of rotors to try\n"
                << "  -c, --ciphertext <path to ciphertext file>                Path the ciphertext file\n"
                << "  -R, --reflector <wiring>                                  Specify the reflector wiring\n"
                << "  -r, --rotors                                              Find the most likely rotor configuration\n"
                << "  -p  --plugboard <rotor configuration>                     Find the most likely plugboard connections\n"
                << "\n"
                << "Example:          ioc-attack --rotor-number 5 --ciphertext ./ciphertext.txt --rotors\n\n"
                << "If it returns the following configuration:\n"
                << "        Reflector:          B\n"
                << "        Rotors:             I IV III\n"
                << "        Ring settings:      A  F  S\n"
                << "        Starting positions: Q  G  N\n\n"
                << "The following step is to find the plugboard connections:\n"
                << "                  ioc-attack --ciphertext ./ciphertext.txt --plugboard B I A Q IV F G III S N\n"
                << "\n"
                << "The attack is based on the index of coincidence (IoC) to decrypt enigma encoded messages\n"
                << "It contains two steps:\n"
                << "    - finding the rotor configuration (-r)\n"    
                << "    - finding the plugboard connections (-p)\n"
                << "For more information about how the attack works: ./ioc-attack -h attack\n";
    }
    
}
