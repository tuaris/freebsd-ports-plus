MASTERDIR=	${.CURDIR}/../zetacoin
PKGNAMESUFFIX=	-daemon

COMMENT=	Virtual Peer-to-Peer Currency (Daemon)

SLAVE_PORT=	yes

USE_RC_SUBR=	zetacoind

CMAKE_ARGS=	-DBUILD_DAEMON=ON \
		-DBUILD_BITCOIN_BIN=OFF \
		-DBUILD_CLI=OFF \
		-DBUILD_GUI=OFF \
		-DBUILD_SHARED_LIBS=OFF \
		-DBUILD_TX=OFF \
		-DBUILD_UTIL=OFF \
		-DBUILD_WALLET_TOOL=OFF

USERS=		zetacoin
GROUPS=		zetacoin

PLIST_FILES=	"@sample %%ETCDIR%%.conf.sample" \
		bin/zetacoind \
		libexec/zetacoin-node \
		share/man/man1/zetacoind.1.gz

OPTIONS_DEFINE=		DEBUG HARDENING TESTS WALLET ZMQ
OPTIONS_DEFAULT=	HARDENING WALLET ZMQ

post-install:
	${INSTALL_DATA} ${FILESDIR}/zetacoin.conf ${STAGEDIR}${PREFIX}/etc/zetacoin.conf.sample

.include "${MASTERDIR}/Makefile"
