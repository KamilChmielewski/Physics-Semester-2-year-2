#include "Appearance.h"

Appearance::Appearance(Geometry geometry, Material material, ID3D11DeviceContext * pImmediateContext) : _geometry(geometry), _material(material), _pImmediateContext(pImmediateContext)
{
}

Appearance::~Appearance()
{
}

void Appearance::Draw()
{
	_pImmediateContext->IASetVertexBuffers(0, 1, &_geometry.vertexBuffer, &_geometry.vertexBufferStride, &_geometry.vertexBufferOffset);
	_pImmediateContext->IASetIndexBuffer(_geometry.indexBuffer, DXGI_FORMAT_R16_UINT, 0);

	_pImmediateContext->DrawIndexed(_geometry.numberOfIndices, 0, 0);
}
