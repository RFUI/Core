Pod::Spec.new do |s|
  s.name             = 'RFUICore'
  s.version          = '0.1.0'
  s.summary          = 'Type defines for RFUI.'

  s.homepage         = 'https://github.com/RFUI/Core'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'BB9z' => 'bb9z@me.com' }
  s.source           = { :git => 'https://github.com/RFUI/Core.git', :tag => s.version.to_s }

  s.requires_arc = true
  s.ios.deployment_target = '6.0'

  s.source_files = ['*.{h,m}']
  s.public_header_files = ['*.h']
  s.dependency 'RFKit'
end
