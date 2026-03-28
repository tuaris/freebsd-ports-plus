PKGNAMESUFFIX=	-utils

COMMENT=	Virtual Peer-to-Peer Currency (CLI and Utilities)

SLAVE_PORT=	yes

CMAKE_ARGS=	-DBUILD_BITCOIN_BIN=ON \
		-DBUILD_CLI=ON \
		-DBUILD_TX=ON \
		-DBUILD_UTIL=ON \
		-DBUILD_DAEMON=OFF \
		-DBUILD_GUI=OFF \
		-DBUILD_SHARED_LIBS=OFF

MASTERDIR=	${.CURDIR}/../zetacoin

PLIST_FILES=	bin/zetacoin \
		bin/zetacoin-cli \
		bin/zetacoin-tx \
		bin/zetacoin-util \
		share/man/man1/zetacoin-cli.1.gz \
		share/man/man1/zetacoin-tx.1.gz \
		share/man/man1/zetacoin-util.1.gz \
		share/man/man1/zetacoin.1.gz

OPTIONS_DEFINE=		DEBUG HARDENING TESTS WALLET
OPTIONS_DEFAULT=	HARDENING TESTS WALLET

WALLET_CMAKE_BOOL+=	ENABLE_WALLET_TOOL
WALLET_PLIST_FILES+=	bin/zetacoin-wallet \
			share/man/man1/zetacoin-wallet.1.gz

.include "${MASTERDIR}/Makefile"
