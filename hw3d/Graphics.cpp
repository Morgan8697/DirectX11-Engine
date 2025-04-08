#include "Graphics.h"

#pragma comment(lib, "d3d11.lib")

Graphics::Graphics(HWND hWnd)
{
	// Setting up parameters for the swapchain
	DXGI_SWAP_CHAIN_DESC sd = {};
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator = 0;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.SampleDesc.Count = 1;   // Sets no anti-aliasing
	sd.SampleDesc.Quality = 0; // Sets no anti-aliasing
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; 
	sd.BufferCount = 1; // Double buffering -> one back buffer
	sd.OutputWindow = hWnd;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = 0;

	// This create the device, front/back buffers, swap chain and rendering context
	// Reminder: front buffer is the ready frame that is going to be sent to the lcd
	// and back buffer is the current frame we are renderind
	D3D11CreateDeviceAndSwapChain(
		nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0,
		D3D11_SDK_VERSION, &sd, &pSwap, &pDevice, nullptr, &pContext);

	// Get access to the back buffer
	ID3D11Resource* pBackBuffer = nullptr;
	pSwap->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&pBackBuffer));
	pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &pTarget);

	pBackBuffer->Release();
}

Graphics::~Graphics()
{
	if (pDevice != nullptr)
	{
		// COM way to deallocate memory
		pDevice->Release();
	}
	if (pSwap != nullptr)
	{
		// COM way to deallocate memory
		pDevice->Release();
	}
	if (pContext != nullptr)
	{
		// COM way to deallocate memory
		pDevice->Release();
	}
	if (pTarget != nullptr)
	{
		// COM way to deallocate memory
		pDevice->Release();
	}
}

void Graphics::EndFrame() 
{
	// Presents the rendered frame to the screen.
	// Parameters:
	// - '1u': Sync interval, specifies vertical synchronization (VSync).
	//         0 = No VSync (immediate), 1 = Sync to the screen refresh rate.
	// - '0u': Presentation flags (e.g., DXGI_PRESENT flags), typically 0 for default behavior.
	pSwap->Present(1u, 0u);
}