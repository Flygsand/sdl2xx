#ifndef _SDL2XX__NET_HPP__
#define _SDL2XX__NET_HPP__

namespace SDL {
namespace Net {

	using SocketSet = std::unique_ptr<_SDLNet_SocketSet, decltype(&SDLNet_FreeSocketSet)>;
	using TCPSocket = std::unique_ptr<_TCPsocket, decltype(&SDLNet_TCP_Close)>;
	using UDPPacket = std::unique_ptr<UDPpacket, decltype(&SDLNet_FreePacket)>;
	using UDPSocket = std::unique_ptr<_UDPsocket, decltype(&SDLNet_UDP_Close)>;

	inline SocketSet CreateSocketSet(int maxsockets) {
		return impl::Create(SDLNet_AllocSocketSet, SDLNet_FreeSocketSet, maxsockets);
	}

	inline TCPSocket CreateTCPSocket(IPaddress* ip) {
		return impl::Create(SDLNet_TCP_Open, SDLNet_TCP_Close, ip);
	}

	inline UDPPacket CreateUDPPacket(int size) {
		return impl::Create(SDLNet_AllocPacket, SDLNet_FreePacket, size);
	}

	inline UDPSocket CreateUDPSocket(Uint16 port) {
		return impl::Create(SDLNet_UDP_Open, SDLNet_UDP_Close, port);
	}
}
}

#endif /* _SDL2XX__NET_HPP__ */
