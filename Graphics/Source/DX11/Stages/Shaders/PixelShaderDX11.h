#include "../Fixed/InputAssemblerDX11.h"
#include "../../Other/BlobDX11.h"

namespace Anubis
{
	class PixelShaderDX11
	{
	protected:
		ID3D11PixelShader*	m_pShader;

	public:
		PixelShaderDX11() { m_pShader = NULL; }
		~PixelShaderDX11() { SAFE_RELEASE(m_pShader); }

		AVOID Set() const;

		ABOOL Create(BlobDX11 & shaderbuffer);
		ABOOL CreateAndCompile(const AWSTRING & fileName, const ASTRING & entrypoint, BlobDX11 * pErrors = NULL);
	};
}; //Anubis