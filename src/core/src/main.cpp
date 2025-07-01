
#include <iostream>
#include <string>
#include "core/oneture_core.h"
#include "core/wallet.h"
#include "core/miner.h"

// العنوان المؤسس الافتراضي
const std::string FOUNDER_ADDRESS = "1ONETUREFounderAddress000000000000000";

int main() {
    Blockchain blockchain;

    // إنشاء محفظة المؤسس
    blockchain.CreateWallet(FOUNDER_ADDRESS);

    // اضافة 5 مليون عملة للمؤسس (5,000,000 * 100,000,000 ساتوشي = 5e14)
    Wallet* founderWallet = blockchain.GetWallet(FOUNDER_ADDRESS);
    if (founderWallet) {
        founderWallet->AddBalance(5000000 * COIN);
        std::cout << "Founder wallet credited with 5 million ONE coins.\n";
    }

    // إنشاء مدراء المحفظة و التعدين
    WalletManager walletManager(blockchain);
    Miner miner(blockchain);

    // عرض رصيد المؤسس
    walletManager.ShowBalance(FOUNDER_ADDRESS);

    // بدء التعدين (مثال)
    miner.Stake();

    return 0;
}
